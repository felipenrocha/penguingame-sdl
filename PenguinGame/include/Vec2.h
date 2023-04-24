class Vec2 {
public:
	float x, y;
	Vec2 mul_escalar_vec(float escalar);
	Vec2 soma_vec(const Vec2& v);
	Vec2 sub_vec(const Vec2& v);
	float magnitude();

	Vec2(float _x, float _y) : x(_x), y(_y) {}
	~Vec2() {}
};