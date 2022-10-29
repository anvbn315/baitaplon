#pragma once

class Point{
	private:
	float firstExam; 
	float secondExam;
	float finalExam;
	 
	float component;// diem thanh phan
	float attendance;// diem chuyen can
	
	float eOtCourse;// dem ket thuc hoc phan
	
	public:
	void inputPoint();
	void outputPoint();
	
	void pointEvaluation(); //danh gia diem tren thang 4 
	void componentScoring(); //tinh diem thanh phan
	void eOtCourseScoring(); // tinh diem ket thuc hoc phan
};

