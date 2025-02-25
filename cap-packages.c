#include <windows.h>
#include <fwpmu.h>
#include <stdio.h>

#pragma comment(lib, "Fwpuclnt.lib")

void block_ip(const wchar_t *ip_address)
{
    HANDLE engineHandle = NULL;
    FWPM_SESSION0 session = {0};
    FWPM_FILTER0 filter = {0};

    // Abrir sessão com a WFP
    if (FwpmEngineOpen0(NULL, RPC_C_AUTHN_WINNT, NULL, &session, &engineHandle) != ERROR_SUCCESS)
    {
        printf("Erro ao abrir engine WFP\n");
        return;
    }

    // Configurar filtro para bloquear o IP
    filter.displayData.name = L"Bloqueio de IP";
    filter.layerKey = FWPM_LAYER_ALE_AUTH_CONNECT_V4;
    filter.action.type = FWP_ACTION_BLOCK;
    filter.numFilterConditions = 1;

    FWPM_FILTER_CONDITION0 condition = {0};
    condition.fieldKey = FWPM_CONDITION_IP_REMOTE_ADDRESS;
    condition.matchType = FWP_MATCH_EQUAL;
    condition.conditionValue.type = FWP_UINT32;
    InetPton(AF_INET, ip_address, &condition.conditionValue.uint32);

    filter.filterCondition = &condition;

    if (FwpmFilterAdd0(engineHandle, &filter, NULL, NULL) != ERROR_SUCCESS)
    {
        printf("Erro ao adicionar filtro WFP\n");
    }
    else
    {
        printf("IP %ls bloqueado com sucesso!\n", ip_address);
    }

    FwpmEngineClose0(engineHandle);
}

// Configure as shown in the repo
int main()
{
    block_ip(L"192.168.1.100");
    return 0;
}
