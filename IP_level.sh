#Configurare un'interfaccia di rete
ifconfig <iface> <ip> 

#Vedere configurazione di un'interfaccia di rete
ifconfig <iface>
    -a #tutte le interfacce di rete
#Settare gli hostname associati agli indirizzi IP
vi /etc/hosts

#Configurare le interfacce di rete
vi /etc/network/interfaces
#conf statica
auto <iface>
iface <iface> inet static
    address <ip>
    netmask <netmask>
    gateway <gateway>

#attivare interfaccia di rete con la configurazione del file /etc/network/interfaces
ifup <iface>
ifdown <nic> #deconfigurare l'interfaccia di rete
    -a #per tutte le interfacce di rete
    -n #non eseguire il comando, solo mostrare cosa farebbe