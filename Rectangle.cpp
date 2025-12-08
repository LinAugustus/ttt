
class Rectangle {
	public:
		Rectangle(double input_w, double input_h);
		double get_perimeter();
		double get_area();
		void resize(double factor);
	private:
		double width;
		double height;
};

Rectangle::Rectangle(double h, double w)
{
    height=h;
    width=w;

}

double Rectangle::get_perimeter()
{
    return 2*(height+width);
}

double Rectangle::get_area()
{
    return height*width;
}

void Rectangle::resize(double factor)
{
    height*=factor;
    width*=factor;
}