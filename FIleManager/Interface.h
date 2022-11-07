#pragma once

struct IUpDownArrows
{
	virtual void Up() = 0;
	virtual void Down() = 0;
};

struct IBackspace
{
	virtual void Back() = 0;
};

struct IEnter
{
	virtual void Enter() = 0;
};

struct ICCP
{
	virtual void Cut() = 0;
	virtual void Copy() = 0;
	virtual void Paste() = 0;
};

struct IDeleteCreate
{
	virtual void Create() = 0;
	virtual void Delete() = 0;
};

struct IRename
{
	virtual void Rename() = 0;
};