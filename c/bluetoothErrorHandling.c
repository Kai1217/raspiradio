#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>
#include <string.h>
#include <errno.h>

int main() {
    int dev_id = hci_get_route(NULL);
    if (dev_id < 0) {
        fprintf(stderr, "error code %d: %s\n", errno, strerror(errno));
        exit(1);
    }
}
