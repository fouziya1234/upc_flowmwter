  long int hexToInt(uint16_t h2, uint16_t h1) {
    uint8_t xlow = h2 & 0xff;
    uint8_t xhigh = (h2 >> 8);
    uint8_t ylow = h1 & 0xff;
    uint8_t yhigh = (h1 >> 8);

    // long val = 0;
    uint32_t val = 0;
    val += xhigh << 24;
    val += xlow << 16;
    val += yhigh << 8;
    val += ylow;

    return val;

  }
