#include "../relay.h"

int main(int argc, char *argv[]) {
  if (relay_setup(argv[1]) < 0) {
    return -1;
  }

  /***** SWITCH LOGIC START *****/

  ON(100); // turn on relay for 100ms

  /****** SWITCH LOGIC END ******/

  // relay automatically goes OFF here
  relay_reset();

  return 0;
}

