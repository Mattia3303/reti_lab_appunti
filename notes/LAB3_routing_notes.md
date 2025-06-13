# LAB routing
- nelle'es finale, bisognava mettere una regola di routing in h2 per fare da gateway a h3
    post-up ip route add 1.1.1.1/32 dev eth0.30 
    ATTENZIONE: non mette un gateway, ma aggiunge solo una riga alla tabella di routing

    Questo bisogna farlo perché eth0.30 e ext non sono nella stessa rete
    E' lo stesso motivo per cui senza gateway non si riesce a pingare ad un IP di un net_id diverso 