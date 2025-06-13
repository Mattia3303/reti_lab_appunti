# LAB2


## Ricorda
- finché ci sono interfacce di rete a disposizione
    - modalità untagged tra swicth e host
    - mod untagged tra swicth
- quando non ci sono più iface a disp (es aggiunta di h5)
    si crea un interfaccia virtuale 
    si crea una vlan con la porta che va verso h5 in mod tagged

# Nota che
Dopo aver aggiunto h5, se fai harping da h5 verso 192.168.2.1 (addr della virt iface), vedrai traffico sia da eth0 che da eth0.30
Infatti il traffico passa inevitabilmente anche dall'iface fisica, MA:
sono traffici di tipo diverso
- da eth0 passa del traffico 802.1Q, ignorato da protocollo arping
- da eth0.30 è effettivamente arping

