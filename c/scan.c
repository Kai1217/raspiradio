#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

int main(int argc, char **argv) {
    inquiry_info *ii = NULL;
    int maxRSP, numRSP;
    int deviceID, socket, len, flags;
    int i;
    char address[19] = { 0 };
    char name[248] = { 0 };

    deviceID = hci_get_route(NULL);
    socket = hci_open_dev(deviceID);
    if (deviceID < 0 || socket < 0) {
        perror("Opening Socket");
        exit(1);
    }
    len = 8;
    maxRSP = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(maxRSP * sizeof(inquiry_info));
    numRSP = hci_inquiry(deviceID, len, maxRSP, NULL, &ii, flags);
    if (numRSP < 0) perror("hci_inquiry");

    for (i = 0; i < numRSP; i++) {
        ba2str(&(ii+i)->bdaddr, address);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(socket, &(ii+i)->bdaddr, sizeof(name), name, 0) < 0)
        strcpy(name, "[unknown]");
        printf("%s %s\n", address, name);
    }
    free(ii);
    close(socket);
    return 0;
}