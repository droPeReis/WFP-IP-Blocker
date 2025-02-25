#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>

static struct nf_hook_ops netfilter_ops;

unsigned int block_packets(void *priv, struct sk_buff *skb, const struct nf_hook_state *state)
{
    struct iphdr *ip_header = ip_hdr(skb);

    if (ip_header && ip_header->saddr == in_aton("192.168.1.100"))
    {
        printk(KERN_INFO "Bloqueando pacote de 192.168.1.100\n");
        return NF_DROP;
    }
    return NF_ACCEPT;
}

static int __init firewall_init(void)
{
    netfilter_ops.hook = block_packets;
    netfilter_ops.pf = PF_INET;
    netfilter_ops.hooknum = NF_INET_PRE_ROUTING;
    netfilter_ops.priority = NF_IP_PRI_FIRST;
    nf_register_net_hook(&init_net, &netfilter_ops);
    return 0;
}

static void __exit firewall_exit(void)
{
    nf_unregister_net_hook(&init_net, &netfilter_ops);
}

module_init(firewall_init);
module_exit(firewall_exit);
MODULE_LICENSE("GPL");
