class Shape
{
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
private:
	Shape* next;

protected:
	virtual void draw();
};