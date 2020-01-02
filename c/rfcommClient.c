#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv) {
    struct sockaddr_rc addr = { 0 };
    int s, status;
    char dest[18] = "B8:27:EB:85:59:E3";
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba(dest, &addr.rc_bdaddr);
    status = connect(s,(struct sockaddr *)&addr, sizeof(addr));
    if (status == 0) {
        status = write(s, "Hello!", 6);
    }

    if (status < 0) perror("No");

    close(s);
    return 0;
}