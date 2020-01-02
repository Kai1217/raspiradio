#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv) {
    struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };
    char buffer[1024] = { 0 };
    int s, client, bytesRead;
    socklen_t opt = sizeof(rem_addr);

    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    loc_addr.rc_family = AF_BLUETOOTH;
    loc_addr.rc_bdaddr = *BDADDR_ANY;
    loc_addr.rc_channel = (uint8_t) 1;
    bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));
    listen(s,1);
    client = accept(s, (struct sockaddr *)&rem_addr, &opt);
    ba2str(&rem_addr.rc_bdaddr, buffer);
    fprintf(stderr, "Accepted Connection from %s\n", buffer);
    memset(buffer, 0, sizeof(buffer));
    bytesRead = read(client, buffer, sizeof(buffer));
    if (bytesRead > 0) {
        printf("Recieved [%s]\n", buffer);
    }
    close(client);
    close(s);
    return 0;
}