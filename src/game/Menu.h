/*
 * Menu.h
 *
 *  Created on: Jan 22, 2012
 *      Author: Simon
 */

#ifndef MENU_H_
#define MENU_H_

#include "Tool.h"

class Menu
{
	char icon;
	string description;
	vector<Tool*> tools;
public:
	Menu(char icon_, string description_):
		icon(icon_),
		description(description_),
		tools(vector<Tool*>())
	{

	}

	vector<Tool*> GetToolList()
	{
		return tools;
	}

	char GetIcon()
	{
		return icon;
	}

	string GetDescription()
	{
		return description;
	}

	void AddTool(Tool * tool_)
	{
		tools.push_back(tool_);
	}
};


#endif /* MENU_H_ */