# IMPORTANTE PER CREARE LA CONNETTIVITA TRA TUTTI GLI HOST (COMPRESO QUELLO CHE RAPPRESENTA INTERNET)
- Dentro la stessa macchina (quind il GateWay), quando arriva un pacchetto ad un interfaccia, esso viene virtualmente mandato a tutte le altre interfacce.
Quindi (supponiamo eth1 e eth0 in due reti diverse):
1) Se arriva un pacchetto a eth0 che ha come destinazione un host nella rete di eth1, questo viene mandato SENZA NESSUNA REGOLA DI ROUTING

2) Se invece il pacchetto non è destinato alla rete di eth1, ma ad un host connesso fisicamente a eth1 (come spesso è l'host di internet), allora bisogna solo configurare la regola di routing per l'interfaccia eth1, che NEL FILE INTERFACES (SOTTO eth1) E':
post-up ip route add 2.3.4.5/32 dev eth1 (va specificato anche se sotto la config di eth1)