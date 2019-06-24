#include "UserInterface.h"


UserInterface::UserInterface() {

	buttons.push_back(new Button(100, 500, L".//drawable//freehand.bmp", new PenTool()));
	buttons.push_back(new Button(160, 500, L".//drawable//rectangle.bmp", new SquareTool()));
	buttons.push_back(new Button(220, 500, L".//drawable//circle.bmp", new CircleTool()));
	buttons.push_back(new Button(280, 500, L".//drawable//line.bmp", new LineTool()));
	buttons.push_back(new Button(340, 500, L".//drawable//delete.bmp", new RemoveTool()));
	buttons.push_back(new Button(400, 500, L".//drawable//move.bmp", new MoveTool()));
	buttons.push_back(new Button(460, 500, L".//drawable//save.bmp", new SaveTool()));
	buttons.push_back(new Button(520, 500, L".//drawable//open.bmp", new LoadTool()));
	buttons.push_back(new Button(580, 500, L".//drawable//colourchange.bmp", new ChangeColourTool()));

	buttons.push_back(new Button(723, 320, L".//drawable//redfill.bmp", new RedFillTool()));
	buttons.push_back(new Button(723, 380, L".//drawable//greenfill.bmp", new GreenFillTool));
	buttons.push_back(new Button(723, 440, L".//drawable//bluefill.bmp", new BlueFillTool()));
	buttons.push_back(new Button(723, 120, L".//drawable//redpen.bmp", new RedPen()));
	buttons.push_back(new Button(723, 180, L".//drawable//bluepen.bmp", new BluePen()));
	buttons.push_back(new Button(723, 240, L".//drawable//greenpen.bmp", new GreenPen()));


	selected = buttons.at(0);
	buttons.at(0)->setSelected(true);


	slider = new Slider();
}


UserInterface::~UserInterface()
{
	for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); it++) {
		delete *it;
		*it = nullptr;
	}

	

	delete slider;

}

void UserInterface::onDraw() {

	clrscr(clWhite);
	Data::getData()->reDraw(this);
	reDraw();
	EasyGraphics::onDraw();

}

bool UserInterface::isButtonClicked(int x, int y) {
	for (int i = 0; i < 15; i++) { //change depending on buttons
		if (buttons.at(i)->clicked(x, y)) {
			setBtnsFalse();
			selected = buttons.at(i);
			buttons.at(i)->setSelected(true);
			return true;
		}
	}
	if (slider->clicked(x, y)) {
		return true;
	}
	return false;
}

void UserInterface::setBtnsFalse() {
	for (int i = 0; i < 15; i++) {
		buttons.at(i)->setSelected(false);
	}
}


void UserInterface::reDraw() {

	setPenColour(clWhite, 2);
	for (Button* btn : buttons) {
		btn->drawButton(this);
	}
	slider->draw(this);

}

void UserInterface::onLButtonDown(UINT nFlags, int x, int y) {

	clicked = true;
	mouseDownX = x;
	mouseDownY = y;

	if (!isButtonClicked(x, y)) {
		selected->useTool(x, y, x, y, mouseDownX, mouseDownY, this);
	}

	if (dynamic_cast<FillTool*>(selected->getTool()) != nullptr) {
		selected->useTool(x, y, x, y, mouseDownX, mouseDownY, this);
	}

	if (dynamic_cast<PenColourTool*>(selected->getTool()) != nullptr) {
		selected->useTool(x, y, x, y, mouseDownX, mouseDownY, this);
	}

	if (dynamic_cast<SaveTool*>(selected->getTool()) != nullptr) {
		selected->useTool(x, y, x, y, mouseDownX, mouseDownY, this);
	}

	if (dynamic_cast<LoadTool*>(selected->getTool()) != nullptr) {
		selected->useTool(x, y, x, y, mouseDownX, mouseDownY, this);
	}

	if (dynamic_cast<ChangeColourTool*>(selected->getTool()) != nullptr) {
		if (Data::getData()->shapeClick(x, y)) {
			selected->useTool(x, y, x, y, mouseDownX, mouseDownY, this);
		}
	}

	onDraw();
}

void UserInterface::onLButtonUp(UINT nFlags, int x, int y) {
	clicked = false;
	onDraw();
}

void UserInterface::onMouseMove(UINT nFlags, int x, int y) {


	if (clicked && slider->clicked(mouseDownX, mouseDownY)) {
		slider->setPenW();
		slider->keepInBound();
		slider->move(y, mouseDownY);
		mouseDownY = y;
	}

	if (!isButtonClicked(mouseDownX, mouseDownY) && clicked) {
		if (dynamic_cast<SquareTool*>(selected->getTool()) != nullptr) {
			Square* s = (Square*)Data::getData()->getTopShape();
			s->edit(mouseDownX, mouseDownY, x, y);

		}

		if (dynamic_cast<CircleTool*>(selected->getTool()) != nullptr) {
			Circle* c = (Circle*)Data::getData()->getTopShape();
			c->edit(mouseDownX, mouseDownY, x, y);

		}

		if (dynamic_cast<LineTool*>(selected->getTool()) != nullptr) {
			Line* l = (Line*)Data::getData()->getTopShape();
			l->edit(x, y);

		}

		if (dynamic_cast<MoveTool*>(selected->getTool()) != nullptr) {

			selected->useTool(x, y, x, y, mouseDownX, mouseDownY, this);
			mouseDownX = x;
			mouseDownY = y;
		}

		if (dynamic_cast<PenTool*>(selected->getTool()) != nullptr && clicked) {

			Brush* b = dynamic_cast<Brush*>(Data::getData()->getTopShape());
			b->addPoint(x, y);
			
		}
	}
	onDraw();
}

