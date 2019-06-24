#include "Data.h"

Data* Data::instantiation = nullptr;

Data* Data::getData() {
	if (!instantiation) {
		instantiation = new Data();
	}
	return instantiation;
}

void Data::reDraw(EasyGraphics* easyGraphics) {
	/*for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
	*it.draw();
	}*/
	/*for (int i = 0; i < buttons.size(); i++) {
	buttons.at(i)->drawButton(easyGraphics);
	}*/
	for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
		(*it)->draw(easyGraphics);
	}
	/*for (int i = 0; i < shapes.size(); i++) {
		shapes.at(i)->draw(easyGraphics);
	}*/
}
void Data::changeColour(int index) {
	if (selectedShape != nullptr) {
		selectedShape->setColour(penColour);
		selectedShape->setFillColour(fillColour);
	}

}

void Data::drawSquare(int x, int y, int x2, int y2, EasyGraphics* easyGraphics) {

	Square* s = new Square(x, y, y2 - y, x2 - x);
	s->setFillColour(fillColour);
	s->setColour(penColour);
	s->setPenWidth(penWidth);
	s->draw(easyGraphics);
	shapes.push_back(s);
	//s->setHeight(y2 - y);
	//s->setWidth(x2 - x);
	//int width = LBtnUp.x - LBtnDown.x;
	//int height = LBtnUp.y - LBtnDown.y;
	//easyGraphics->selectBackColour(EasyGraphics::clRed);


	//easyGraphics->drawRectangle(LBtnDown.x, LBtnDown.y, width, height, true);
}

void Data::drawLine(int x, int y, int x2, int y2, EasyGraphics* easyGraphics) {

	Line* l = new Line(x, y, x2, y2);
	l->setFillColour(fillColour);
	l->setColour(penColour);
	l->setPenWidth(penWidth);
	shapes.push_back(l);
	l->draw(easyGraphics);

	//l->drawALine(easyGraphics);
	//easyGraphics->drawLine(LBtnDown.x, LBtnDown.y, LBtnUp.x, LBtnUp.y);
}

void Data::drawCircle(int x, int y, EasyGraphics* easyGraphics) {
	Circle* c = new Circle(x, y, 0);
	c->setFillColour(fillColour);
	c->setColour(penColour);
	c->setPenWidth(penWidth);
	c->draw(easyGraphics);
	shapes.push_back(c);

	//easyGraphics->drawCircle(x,y,59,false);
}

void Data::drawBrush(int x, int y, EasyGraphics* easyGraphics) {
	Brush* b = new Brush(x, y);
	b->setColour(penColour);
	b->setPenWidth(penWidth);
	shapes.push_back(b);
}

void Data::removeShape(int index) {
	if (index != -1) {
		shapes.erase(shapes.begin() + index);
	}
}

void Data::moveShape(int index, int x, int y, int x2, int y2, int mouseDownX, int mouseDownY) {

	if (index != -1) {

		Shape* s = shapes.at(index);
		shapes.erase(shapes.begin() + index);
		shapes.push_back(s);
		int tempX = s->getX() - (mouseDownX - x);
		int tempY = s->getY() - (mouseDownY - y);

		if (dynamic_cast<Line*>(s) != nullptr) {
			int tempReleaseX = s->getX2() - (mouseDownX - x);
			int tempReleaseY = s->getY2() - (mouseDownY - y);
			s->move(tempX, tempY, tempReleaseX, tempReleaseY);
		}
		else {
			s->move(tempX, tempY, mouseDownX, mouseDownY);
		}

	}

}

bool Data::shapeClick(int x, int y) {
	for (int i = shapes.size() - 1; i > -1; i--) {
		if (shapes.at(i)->clicked(x, y)) {
			return true;
		}
	}
	return false;
}

int Data::returnShapeIndex(int x, int y) {

	//std::vector<Shape*>::iterator it = std::find_if(shapes.begin(), shapes.end(), clicked(x, y));

	for (int i = shapes.size() - 1; i > -1; i--) {
		if (shapes.at(i)->clicked(x, y)) {
			return i;
		}
	}
	return -1;
}

void Data::save() {
	int messageBox;
	saveSize = shapes.size();
	string type; //add error handling.
	ofstream fout;
	fout.open("savedata.txt", ios::out);
	if (fout.fail()) {
		messageBox = MessageBox(NULL, L"Save error", L"error", MB_OK); 
	}
	else{
		for (int i = 0; i < shapes.size(); i++) {

			if (dynamic_cast<Square*>(shapes.at(i)) != nullptr) {
				type = "square";
				fout << type + " ";
				fout << to_string(shapes.at(i)->getX()) + " ";
				fout << to_string(shapes.at(i)->getY()) + " ";
				fout << to_string(dynamic_cast<Square*>(shapes.at(i))->getWidth()) + " ";
				fout << to_string(dynamic_cast<Square*>(shapes.at(i))->getHeight()) + " ";
			}
			if (dynamic_cast<Circle*>(shapes.at(i)) != nullptr) {
				type = "circle";
				fout << type + " ";
				fout << to_string(shapes.at(i)->getX()) + " ";
				fout << to_string(shapes.at(i)->getY()) + " ";
				fout << to_string(dynamic_cast<Circle*>(shapes.at(i))->getRadius()) + " ";
			}
			if (dynamic_cast<Line*>(shapes.at(i)) != nullptr) {
				type = "line";
				fout << type + " ";
				fout << to_string(shapes.at(i)->getX()) + " ";
				fout << to_string(shapes.at(i)->getY()) + " ";
				fout << to_string(shapes.at(i)->getX2()) + " ";
				fout << to_string(shapes.at(i)->getY2()) + " ";
			}


			fout << to_string(shapes.at(i)->getColour()) + " ";
			fout << to_string(shapes.at(i)->getFillColour()) + " ";
			fout << to_string(shapes.at(i)->getPenWidth()) + "\n";

		}
		messageBox = MessageBox(NULL, L"Save Successful", L"Saved", MB_OK); //message box
	}
	
	fout.close();
	
}

void Data::load() {
	string type;
	int x, y, x2, y2, width, height, colour, fillColour, penWidth;
	int i = 0;
	double radius;
	ifstream fin;
	fin.open("savedata.txt", ios::in);
	if (fin.fail())
		int messageBox = MessageBox(NULL, L"Load Error", L"Error", MB_OK); //message box
	else {
		shapes.clear();
	/*	for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
			delete *it;
		}*/
		
		while (fin) {
			fin >> type;
			fin >> x;
			fin >> y;


			if (type == "square") {

				fin >> height;
				fin >> width;
				fin >> colour;
				fin >> fillColour;
				fin >> penWidth;

				shapes.push_back(new Square(x, y, width, height));
			}

			if (type == "line") {

				fin >> x2;
				fin >> y2;
				fin >> colour;
				fin >> fillColour;
				fin >> penWidth;

				shapes.push_back(new Line(x, y, x2, y2));
			}

			if (type == "circle") {
				fin >> radius;
				fin >> colour;
				fin >> fillColour;
				fin >> penWidth;

				shapes.push_back(new Circle(x, y, radius));
			}
			shapes.at(i)->setColour(colour);
			shapes.at(i)->setFillColour(fillColour);
			shapes.at(i)->setPenWidth(penWidth);
			i++;
		}
	}

	
	//int messageBox = MessageBox(NULL, L"Load Successful", L"Saved", MB_OK);
}

