#pragma once
#include "GlobalFunctions\GCommon.h"
#include "WireFrame\WireFrame.h"
#include "Triangle.h"

using namespace std;

class ExtruderCone
{
public:
	ExtruderCone();
	ExtruderCone(
		double height, 
		point base_point, 
		Vec3f normal, 
		double angle
	);
	~ExtruderCone();

public:
	/* Data I/O */
	double	Height() { return height_; }
	double	Angle()	 { return angle_; }
	double	WaveAngle() { return wave_angle_; }
	double ToolLenth(){ return tool_lenth_; }
	double Radii(){ return radii_; }
	double CyclinderLenth(){ return cyclinder_height_; }
	point	BasePoint() { return base_point_; }
	Vec3f	Normal()	{ return normal_; }


	/*top cylidner*/
	double TopCenter(){ return top_cylin_center_lenth_; }
	double TopLenth(){ return top_cylin_lenth_; }
	double TopRadii(){ return top_cylin_radii_; }
	/* Generate Extruder Cone */
	void GeneCone();

	/* Debug Screenplay Function */
	void	Test();

	/* Geometric transformation, for rendering purpose */
	void	RotateTri(Triangle temp);
    point	Multi(point s);
	void	Rotation(double angle, point start, point end);
	void	Rotation(GeoV3 normal, point start, point end);

	/* OpenGL Rendering Interface */
	void	Render(WireFrame* ptr_frame, double alpha);

private:
	/* Extruder Property Data */
	double				angle_;
	double				height_;
	double          tool_lenth_;
	double radii_;
	double cyclinder_height_;

	double				wave_angle_;
    vector<Triangle>	side_;
	point				base_point_;
	Vec3f				normal_;

	/* Extruder Render Data */
	int					divide_;	/* Traingle division for cone	  */
	vector<Triangle>	side_end_;  /* Triangle Approx for the cone   */
	vector<point>		top_;		/* Ploygon represent top covering */

	/* Transformation for Rendering */
	float rotate_[4][4];
	point start_,end_;

	//Top_Cylinder
	double top_cylin_center_lenth_;
	double top_cylin_lenth_;
	double top_cylin_radii_;
};