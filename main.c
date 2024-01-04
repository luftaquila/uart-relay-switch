#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

int device;
const int bit = TIOCM_RTS;

int setup(char *dev);
int OFF(int ms);
int ON(int ms);

int main(int argc, char *argv[]) {
  // 1.5ms bouncing occurs here
  if (setup(argv[1]) < 0) {
    return -1;
  }

  /***** USER LOGIC START *****/

  ON(500); // turn on relay for 500ms

  /****** USER LOGIC END ******/

  close(device); // relay automatically goes OFF here

  return 0;
}

int setup(char *dev) {
  printf("target device: %s\n", dev);

  device = open(dev, O_RDWR);

  if (device < 0) {
    fprintf(stderr, "setup failed: device open error: %s\n", strerror(errno));

    return -1;
  }

  int ret = ioctl(device, TIOCMBIC, &bit);

  if (ret < 0) {
    fprintf(stderr, "setup failed: RTS setup error: %s\n", strerror(errno));

    return -1;
  }

  return 0;
}

int OFF(int ms) {
  int ret = ioctl(device, TIOCMBIC, &bit); // HIGH

  if (ret < 0) {
    fprintf(stderr, "RTS HIGH error: %s\n", strerror(errno));

    return -1;
  }

  usleep(ms * 1000);

  return 0;
}

int ON(int ms) {
  int ret = ioctl(device, TIOCMBIS, &bit); // LOW

  if (ret < 0) {
    fprintf(stderr, "RTS LOW error: %s\n", strerror(errno));

    return -1;
  }

  usleep(ms * 1000);

  return 0;
}
