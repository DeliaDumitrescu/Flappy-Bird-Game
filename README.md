# Flappy Bird Game
###### Developed using C++ and SFML
### Game Presentation
- Give your flappy bird a name and start the game: <br> <br>
![](readmephotos/img4.png) <br> <br>
- Start playing: <br> <br>
![](readmephotos/img1.png) <br> <br>
![](readmephotos/img3.png) <br> <br>
- Restart when you lose: <br> <br>
![](readmephotos/img2.png) <br> <br>
- Close game and see your achievements: <br> <br>
![](readmephotos/img5.png) <br> <br>

### Features
- [x] Graphical Interface (SDL, SFML, Qt, etc.) - C++ API
- [x] RTTI (Run-time type information)
```cpp
Bird* bird = dynamic_cast<Bird*>(_bird);

```
- [x] Abstract Classes
```cpp
class Object
{
  ...
	virtual void draw(sf::RenderWindow&) = 0;
  virtual void manageExceptions() = 0;
  virtual ~Object(){}
};
```
- [x] Overloading Operators
```cpp
std::istream& operator >>(std::istream& in, Bird& bird)
{
    std::cout<< "Enter your bird's name and hit enter: ";
    in >> bird.name;
    return in;
}

And many more!
```
- [x] Heap Memory Allocation
```cpp
ObjectFactory* factory = new ObjectFactory;
```
- [x] Exceptions
```cpp
class Exception : public std::exception
{
   ...
};

class file_not_found_error : public Exception
{
	...
};
```
```cpp
try {
    if (!std::filesystem::exists(fileName)) throw file_not_found_error(fileName);
    else throw 1;
}
catch (const file_not_found_error& err) {
    std::cout << err.what();
}
catch (...) {
    f.loadFromFile(fileName);
    t.setPosition(x, y);
    t.setFont(f);
    t.setOutlineThickness(thickness);
    t.setCharacterSize(size);
    t.setString(s);
}
```
- [x] STL
```cpp
std::priority_queue <int> allScores;
```
- [x] Lambda expressions
```cpp
auto tooLow = [&]() { return bird->getY() > 700 && bird->isAlive(); };
auto tooHigh = [&]() { return bird->getY() < -10 && bird->isAlive(); };
...
if(tooLow() || tooHigh())
{
    score->insertScore();
    bird->die();
}
```
- [x] Templates
```cpp
template <class T>
class Text
{
  ...
};
```
- [x] Smart pointers
```cpp
std::unique_ptr <Score> score = std::make_unique <Score>();
```
- [x] Design patterns
```cpp
//Singleton
class Bird : public Object
{
private:
    ...
    static Bird* instance;
    Bird();
    Bird(const Bird&) = delete;
    Bird(Bird &&) noexcept = delete;
    Bird& operator =(const Bird&) = delete;
    Bird &operator=(Bird &&bird) = delete;
public:
    static Bird* GetInstance();
    ...
};
```
```cpp
//Factory
class ObjectFactory
{
public:
	Object* Create(const char objName[])
	{
		if (objName == "bird") return Bird::GetInstance();
		else if(objName == "pipe") return new Pipe;
		else
		{
			std::cout << "Obiect invalid!\n";
			return nullptr;
		}
	}
};
```
```cpp
//Facade
class Collision
{
private:
	Bird &bird;
	Pipe &first, &second, &third;
	Score &score;
	sf::SoundBuffer buffer;
	sf::Sound coin_sound;

public:
	Collision(Bird &b, Pipe &p1, Pipe &p2, Pipe &p3, Score &s);
	void isCollide();
	void update();
};
```
- [x] Features of C++17/20 (constexpr, consteval, constinit, fold expressions, init statement for if/switch, etc.)
```cpp
if (!std::filesystem::exists(fileName)) throw file_not_found_error(fileName);
```
- [x] Move Semantics
```cpp
Pipe& Pipe::operator =(Pipe&& other)
{
    if (this == &other) return *this;
    x = other.x;
    y = other.y;
    file_up = other.file_up;
    file_down = other.file_down;

    manageExceptions();

    other.x = other.y = 0;
    other.file_up = other.file_down = "";

    return *this;
}
...
// in main
*third = *first + 1000;
```
