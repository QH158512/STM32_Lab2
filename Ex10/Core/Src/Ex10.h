/*
 * Ex10.h
 *
 *  Created on: Sep 29, 2025
 *      Author: laptopaz
 */

#ifndef SRC_EX10_H_
#define SRC_EX10_H_
#include "main.h"
#define MAX_BUFFER 16

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[MAX_BUFFER] = {
    0x18, 0x24, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42,  // "A"
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   // empty space
};

/*
uint8_t matrix_buffer[8] = {			//To make character "A" in binary -> hexadecimal
		0x18 , 							//	00011000
		0x24 , 							// 	00100100
		0x42 , 							//	01000010
		0x7E , 							//	01000010
		0x42 , 							//	01111110
		0x42 , 							//	01000010
		0x42 , 							//	01000010
		0x42							//	01000010
};
*/

uint8_t A_pattern[8] = {
		0x18, 							// ..XX....
		0x24, 							// .X..X...
		0x42, 							// X....X..
		0x42, 							// X....X..
		0x7E, 							// XXXXXX..
		0x42, 							// X....X..
		0x42, 							// X....X..
		0x42  							// X....X..
};


void clearAllColumns(){
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
}

void updateLEDMatrix(int index) {			//This input index is for scanning each COLUMN

	clearAllColumns();

	uint8_t pattern = matrix_buffer[index];

	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, (pattern & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, (pattern & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, (pattern & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, (pattern & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, (pattern & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, (pattern & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, (pattern & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, (pattern & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);

	switch (index){
		case 0:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
			break;

		case 1:
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			break;

		case 2:
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			break;

		case 3:
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
			break;

		case 4:
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
			break;

		case 5:
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			break;

		case 6:
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			break;

		case 7:
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
			break;

		default:
			break;
	}

}

void shiftLeft() {
    for (int i = 0; i < MAX_BUFFER-1; i++) {
        matrix_buffer[i] = matrix_buffer[i+1];
    }
    matrix_buffer[MAX_BUFFER-1] = 0x00; // new column empty
}



#endif /* SRC_EX10_H_ */
