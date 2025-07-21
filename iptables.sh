#GUARDARE LE TABELLE
iptables -t {filter, nat} -L -v -n 

#RICORDA DI USARE OPZIONE -v IN NETCAT PER VERIFICARE CHE SIA CONNESSO
#ATTENZIONE: PACCHETTO IN ENTRATA NEL GW SUBISCE PRIMA IL NAT (in pratica viene seguito
# il normale ordine dettato dagli hook)

#FILTRAGGIO PACCHETTI
    #CHAINS
    INPUT #Ciò che riceve il sistema operativo
    OUTPUT #Ciò che manda il sistema operativo
    FORWARD #Ciò che passa dalla macchina (instradamento)

    #Set default policies (-P)
    iptables -P <chain>  {ACCEPT|DROP}

    #Set filtering rules (-A (add))
    iptables -A <chain> <matching_criteria> -j ACCEPT #sempre accept negli es
        #matching criterias (tutti opz)
        -p <protocol> #tcp, udp, icmp

        -s <source_addr/mask>
        --sport <source_port>
        -d <dest_addr/mask>
        --dport <dest_port>

        -i <input_iface>
        -o <output_iface>

        #Stateful rules
        -m state --state <state> 
            #States
            NEW #Nuova connessione
            ESTABLISHED #Connessione già stabilita
            RELATED #Connessione correlata
            #ATTENZIONE
            udp è connectionless, quindi non va usato -m state


    #Rimovere regole (-D)
    iptables -D ....


#NAT
    #CHAINS
    PREROUTING #Prima che il pacchetto venga instradato
    POSTROUTING #Dopo che il pacchetto è stato instradato
    OUTPUT #Per i pacchetti generati dalla macchina

    #Static NAT
    #Rende possibile usare lo stesso indirizzo IP pubblico per tutte le macchine private
    iptables -t nat -A POSTROUTING -o <iface> -j SNAT --to-source <public_ip>
        #Regola applicata in entrambe le direzioni
        #Agli host privati viene assegnata una porta tra quelle disponibili
    #Masquerading
    #Se si vuole usare l'indirizzo IP della NIC di uscita
    iptables -t nat -A POSTROUTING -o <iface> -j MASQUERADE 

    #Dynamic NAT
    #AD ES se host 192.168.1.1 gestisce un server web che ascolta su porta 80
    #ATTENZIONE: la regola permette solo di inoltrare il traffico destinato a 155.185.54.185:80 a 192.168.1.1:80
    iptables -t nat -A PREROUTING -p tcp -d 155.185.54.185 --dport 80 -j DNAT --to-destination 192.168.1.1