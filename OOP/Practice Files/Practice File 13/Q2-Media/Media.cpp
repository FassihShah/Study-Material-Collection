#include"Media.h"
Media::Media()
{
}
Media::~Media()
{
	title.~String();
}
Media:: Media(String t):title(t)
{
}
String Media::getTitle()
{
	return title;
}
void Media::setTitle(String t)
{
	title = t;
}