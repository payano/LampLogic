#ifndef ITHREAD_H_
#define ITHREAD_H_

class IThread {
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual bool isRunning() = 0;
	virtual ~IThread() {;}



};

#endif /* ITHREAD_H_ */
