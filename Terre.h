#ifndef TERRE_H
#define TERRE_H

class Terre {
	Terre();
	Terre(const Terre& t);
	~Terre();
	Terre& operator=(const Terre& t);
public:
	static double GM;
	static double RT;
	static Terre & getInstance(void);
};

#endif