//! @file 
//! @brief Implementation file for the Item class  
//!

#pragma once
#include <afx.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define _T(x)__T(x)
//! Class implementing a game map
class Map : public CObject
{
public:
	DECLARE_SERIAL(Map);
	Map();
	Map(int row, int col, int startX, int startY, int endX, int endY, CString name);
	~Map();
	int getCol();
	int getRow();
	CString** getGrid();
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	bool validatePath();
	void fillCell(int x, int y, string obj);
	bool isOccupied(int x, int y);
	void printMap();

	void save();
	void load(string name);

	static void createMap();
	static void editMap(string name);

	
	void Serialize(CArchive& archive);
	//DECLARE_SERIAL(Map);

private:

	int row;
	int column;
	CString** grid;
	int startX;
	int startY;
	int endX;
	int endY;
	CString mapName;
	CString nextName;

protected:
	
};


