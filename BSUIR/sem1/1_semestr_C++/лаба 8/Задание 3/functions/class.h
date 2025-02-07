#pragma once

class worker{
private:
    char name[100];
	char job[100];
	long long year_of_work;
public:
	char* getName() {
		return this->name;
	}
	char* getJob() {
		return this->job;
	}
	long long getYear() {
		return this->year_of_work;
	}
	void setName(const char* name) {
	    strcpy_s(this->name, name);
	}
	void setJob(const char* job) {
		strcpy_s(this->job, name);
	}
	void setYear(long long year) {
		this->year_of_work = year;
	}
};
