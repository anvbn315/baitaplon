#pragma once

class Point{
	private:
	float firstExam; 
	float secondExam;
	float finalExam;
	float attendance;// diem chuyen can
	
	float component;// diem thanh phan
	float eOtCourse;// dem ket thuc hoc phan
	
	public:
	void inputPoint();
	void outputPoint();
	
	void pointEvaluation(); //danh gia diem tren thang 4 
	void componentScoring(); //tinh diem thanh phan
	void eOtCourseScoring(); // tinh diem ket thuc hoc phan
	
	float getFirstExam();
	float getSecondExam();
	float getFinalExam();
	float getComponent();
	float getAttendance();
	float getEoTCourse();
	
	void setFirstExam(float point);
	void setSecondExam(float point);
	void setFinalExam(float point);
	void setAttendance(float point);
	void setComponent(float point);
	void setEoTCourse(float point);


};


