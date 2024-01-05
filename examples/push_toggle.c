#include "../relay.h"

int main(int argc, char *argv[]) {
  if (relay_setup(argv[1]) < 0) {
    return -1;
  }

  /***** SWITCH LOGIC START *****/

  // double press to toggle back
  ON(100);
  OFF(300);
  ON(100);

  /****** SWITCH LOGIC END ******/

  // relay automatically goes OFF here
  relay_reset();

  return 0;
}

