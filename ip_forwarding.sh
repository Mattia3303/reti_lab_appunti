#Attivare l'IP forwarding
sysctl -w net.ipv4.ip_forward=1
    #per rendere permanente
    echo "net.ipv4.ip_forward=1" >> /etc/sysctl.conf

#Aggiungere una route statica
ip route add <dest> via <gateway> [dev <iface>]
    #per rimuovere
    ip route del ...

#Aggiungere un default gateway
ip route add default via <gateway> [dev <iface>]

#Configurazioni permanenti
    #default gateway
    address ...
    gateway <ip>
    #route statica
    address ...
    post-up ip route add <dest> via <gateway> [dev <iface>]
#Mostrare le route
ip route show
    #per vedere le route per una destinazione specifica
    ip route show <dest>
    #per vedere le route per una interfaccia specifica
    ip route show dev <iface>

