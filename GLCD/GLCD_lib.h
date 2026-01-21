#include <stdint.h>

/******************************************************************************
* Function Name  : DrawRect
* Description    : Draw a filled or empty rectangle
* Input          : 
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/

void LCD_DrawEmptyRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint8_t EdgeWidth, uint16_t EdgeColor) {
	uint16_t i, j;

	for(i = Xpos; i < (Xpos + Width); i++) {
		for(j = Ypos; j < (Ypos + Height); j++) {
			if((i < (Xpos + EdgeWidth)) || (i >= (Xpos + Width - EdgeWidth)) ||
				 (j < (Ypos + EdgeWidth)) || (j >= (Ypos + Height - EdgeWidth))) {
				LCD_SetPoint(i, j, EdgeColor);
			}
		}
	}
} 

void LCD_DrawFillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint8_t EdgeWidth, uint16_t EdgeColor, uint16_t FillColor) {
	uint16_t i, j;

	for(i = Xpos; i < (Xpos + Width); i++) {
		for(j = Ypos; j < (Ypos + Height); j++) {
			if((i < (Xpos + EdgeWidth)) || 
				 (i >= (Xpos + Width - EdgeWidth)) ||
				 (j < (Ypos + EdgeWidth)) || 
			   (j >= (Ypos + Height - EdgeWidth))) {
				LCD_SetPoint(i, j, EdgeColor);
			} else {
				LCD_SetPoint(i, j, FillColor);
			}
		}
	}
}

#define TEXT_WIDTH_PX 8
#define TEXT_HEIGHT_PX 16

void LCD_DrawFillRectText(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint8_t *text, uint8_t EdgeWidth, uint16_t EdgeColor, uint16_t FillColor, uint16_t TextColor) {
	uint16_t i, j, txtXpos, txtYpos, text_width_px;
	
	//Draw the filled rectangle
	LCD_DrawFillRect(Xpos, Ypos, Width, Height, EdgeWidth, EdgeColor, FillColor);
	
	//Count the text characters number
	i = 0;
	while(text[i] != '\0')
		i++;

	
	//Calculate the text width and lines
	text_width_px = i * TEXT_WIDTH_PX;
	
	//Set the start point of the text
	txtXpos = Xpos + (Width/2) - (text_width_px/2);
	txtYpos = Ypos + (Height/2) - (TEXT_HEIGHT_PX/2);
	
	//Write text
	GUI_Text(txtXpos, txtYpos, text, TextColor, FillColor);
}