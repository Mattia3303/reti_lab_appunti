#attivare interfaccia di rete non configurata
ifconfig <iface> up


#Query ARP
arping  
    -0 #usa l'interfaccia anche se non configurata, con indirizzo 0.0.0.0
    [<ip>] #indirizzo IP da risolvere
    -B #cerca di risolvere l'indirizzo IP 255.255.255.255
    -i <iface> #forza ad usare interfaccia di rete

#info su link
ip link show dev <iface>

