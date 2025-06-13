#VDE Switch 
    #Modfica il file di configurazione (dalla finestra di creazione dello switch di marionnet)
    #Creare due VLAN 
    vlan/create <vlan_num>

    #Set VLAN - port association
    port/setvlan <port_num> <vlan_num> #(UNTAGGED)
        #per disconnettere una porta da una VLAN
        port/setvlan <port_num> 0 #(UNTAGGED)

    #Add a port connected to the other switch to the VLAN
    vlan/addport <vlan_num> <port_num> #(TAGGED)
        #per disconnettere una porta da una VLAN
        #boh
        #Settare la porta untagged
        port/setvlan <port_num> <vlan_num>

    #Show info
    vlan/print

    #Show connection between MAC and ports
    hash/print

#Altro
    #Configurare una VLAN trunk (conf temporanea)
        ip link add link <physif> <virtif> type vlan id <N> #N == tag VLAN
        vconfig add <physif> <N> 
        #Remuval
        ip link delete <virtif>
        vconfig rem <physif>.<N>
    #Configurare una VLAN trunk (permanente)
        vi /etc/network/interfaces
        #come conf interfaccia di rete statica, ma con l'interfaccia che è <physif>.<N>
        auto <physif>.<N>
        iface <physif>.<N> inet static
            address <ip>
            netmask <netmask>
            gateway <gateway>

    #RICORDA DI ATTIVARLA
    ifup <physif>.<N>
