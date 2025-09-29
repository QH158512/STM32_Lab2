/*
 * Ex10_test.h
 *
 *  Created on: Sep 29, 2025
 *      Author: laptopaz
 */

#ifndef SRC_EX10_TEST_H_
#define SRC_EX10_TEST_H_
#include "main.h"

const GPIO_PinState segmentMap[10][7] = {
    //A               B               C               D               E               F               G
    {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET}, // 0
    {GPIO_PIN_SET,   GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_SET,   GPIO_PIN_SET,   GPIO_PIN_SET}, // 1
    {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_RESET}, // 2
    {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_SET,   GPIO_PIN_RESET}, // 3
    {GPIO_PIN_SET,   GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_SET,   GPIO_PIN_RESET, GPIO_PIN_RESET}, // 4
    {GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_RESET, GPIO_PIN_RESET}, // 5
    {GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET}, // 6
    {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_SET,   GPIO_PIN_SET,   GPIO_PIN_SET}, // 7
    {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET}, // 8
    {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,   GPIO_PIN_RESET, GPIO_PIN_RESET}  // 9
};



GPIO_TypeDef* ENM_GPIO_Port[8] = {
    ENM0_GPIO_Port, ENM1_GPIO_Port, ENM2_GPIO_Port, ENM3_GPIO_Port,
    ENM4_GPIO_Port, ENM5_GPIO_Port, ENM6_GPIO_Port, ENM7_GPIO_Port
};

uint16_t ENM_Pin[8] = {
    ENM0_Pin, ENM1_Pin, ENM2_Pin, ENM3_Pin,
    ENM4_Pin, ENM5_Pin, ENM6_Pin, ENM7_Pin
};

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {
    0x3C, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x00
};


void updateLEDMatrix(int index) {
	//Disable all
    for (int i = 0; i < MAX_LED_MATRIX; i++) {
        HAL_GPIO_WritePin(ENM_GPIO_Port[i], ENM_Pin[i], GPIO_PIN_SET);
    }

    if (index < 0 || index >= MAX_LED_MATRIX) {
        return;
    }
    //Set row
    uint8_t colData = matrix_buffer[index];
    for (int row = 0; row < 8; row++) {
        // If bit is 1, pin state is RESET
        GPIO_PinState state = (colData & (1 << row)) ? GPIO_PIN_RESET : GPIO_PIN_SET;
        HAL_GPIO_WritePin(GPIOB, (1 << (8 + row)), state);
    }

    switch (index) {
        case 0:
            HAL_GPIO_WritePin(ENM_GPIO_Port[0], ENM_Pin[0], GPIO_PIN_RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(ENM_GPIO_Port[1], ENM_Pin[1], GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(ENM_GPIO_Port[2], ENM_Pin[2], GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(ENM_GPIO_Port[3], ENM_Pin[3], GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(ENM_GPIO_Port[4], ENM_Pin[4], GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(ENM_GPIO_Port[5], ENM_Pin[5], GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(ENM_GPIO_Port[6], ENM_Pin[6], GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(ENM_GPIO_Port[7], ENM_Pin[7], GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void shiftMatrixUp(void) {
    for (int i = 0; i < MAX_LED_MATRIX - 1; i++) {
        matrix_buffer[i] = matrix_buffer[i + 1];
    }
}


#endif /* SRC_EX10_TEST_H_ */
