//----------------------------------------------------------------------------//
/*
 *  Copyright (C) 2022  Marcon Alessandro
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
//----------------------------------------------------------------------------//


/*
  mux.h - Control multiple muxes with Arduino Uno.
  Created by alessandromrc, 20 July 2021.
*/

#ifndef mux_h
#define mux_h

static constexpr bool MUX_HIGH = 1;
static constexpr bool MUX_LOW = 0;

class Muxer {

private:
  byte s0 = 0;
  byte s1 = 0;
  byte s2 = 0;
  byte s3 = 0;
  byte SIG_pin = 0;
  byte dig_pin = 0;

  byte muxChannel[16][4] = {
      {0, 0, 0, 0}, // channel 0
      {1, 0, 0, 0}, // channel 1
      {0, 1, 0, 0}, // channel 2
      {1, 1, 0, 0}, // channel 3
      {0, 0, 1, 0}, // channel 4
      {1, 0, 1, 0}, // channel 5
      {0, 1, 1, 0}, // channel 6
      {1, 1, 1, 0}, // channel 7
      {0, 0, 0, 1}, // channel 8
      {1, 0, 0, 1}, // channel 9
      {0, 1, 0, 1}, // channel 10
      {1, 1, 0, 1}, // channel 11
      {0, 0, 1, 1}, // channel 12
      {1, 0, 1, 1}, // channel 13
      {0, 1, 1, 1}, // channel 14
      {1, 1, 1, 1}  // channel 15
  };

public:

  void setupAnalog(byte pin1, byte pin2, byte pin3, byte pin4, byte analog_in) {
    s0 = pin1;
    s1 = pin2;
    s2 = pin3;
    s3 = pin4;
    SIG_pin = analog_in;

    pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);

    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
  }

  void setupDigital(byte pin1, byte pin2, byte pin3, byte pin4,
                    byte digital_pin) {
    s0 = pin1;
    s1 = pin2;
    s2 = pin3;
    s3 = pin4;
    dig_pin = digital_pin;

    pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);

    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
  }

  float readMux(int channel) {
    int controlPin[] = {s0, s1, s2, s3};

    for (int i = 0; i < 4; i++) {
      digitalWrite(controlPin[i], muxChannel[channel][i]);
    }
    return analogRead(SIG_pin);
  }

  void writeMux(int channel, float value) {
    int controlPin[] = {s0, s1, s2, s3};

    for (int i = 0; i < 4; i++) {
      digitalWrite(controlPin[i], muxChannel[channel][i]);
    }
    analogWrite(dig_pin, value);
  }

  void writeMux(int channel, bool value) {
    int controlPin[] = {s0, s1, s2, s3};

    for (int i = 0; i < 4; i++) {
      digitalWrite(controlPin[i], muxChannel[channel][i]);
    }
    digitalWrite(dig_pin, value);
  }
};

#endi
