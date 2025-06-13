#Client interface setting
auto eth0
iface eth0 inet dhcp
    #For fixed address 
    hwaddress  ether  <mac>



#Server interface setting
    #normale con IP statico

#Server dns masq configuration
vi /etc/dnsmasq.conf

    #Non guardare altri nameserver 
    no-resolv
    
    #mappatura statica MAC-IP
        #opzione1
            #nella conf
            read-ethers
            #nel file /etc/ethers metto le associazioni mac-ip dei client
                <mac> <ip> 
            #nel file /etc/hosts metto le associazioni ip-hostname-domain del client o anche di te stesso
                <ip> <hostname> <hostname>.<domain>
                #esempio
                192.168.1.254 server server.reti.org
                192.168.1.3 client3 client3.reti.org


        #opzione2
            dhcp-host=<mac>,<hostname>,<ip>,<lease-time>
            #dove <lease-time> è il tempo dopo cui il client deve richiedere un nuovo lease (es. 12h, 1d, 1w, etc.)


    #Range di indirizzi IP da assegnare ai client
    dhcp-range=<start-ip>,<end-ip>[,<netmask>],<lease-time>

    #Interfaccia su cui ascoltare
    interface=<iface>
    #Dominio di ricerca (non so a cosa serva)
    domain=<domain>

    #Settaggio del default gateway ai client
    dhcp-option=3,<gateway-ip>
    #Settaggio del DNS ai client
    dhcp-option=6,<dns-ip>



