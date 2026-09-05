#include "Anime.h"
#include "doctest.h"

TEST_CASE("Anime 构造器：超上限评分被钳制为 0")
{
	Anime a("名", "作者", "描述", 99.0f);
	CHECK(a.getRate() == 0.0f);
}

TEST_CASE("Anime 构造器：负数评分被钳制为 0")
{
	Anime a("名", "作者", "描述", -3.0f);
	CHECK(a.getRate() == 0.0f);
}

TEST_CASE("Anime 构造器：合法评分原样保留")
{
	Anime a("名", "作者", "描述", 8.5f);
	CHECK(a.getRate() == doctest::Approx(8.5f));   // float 比较必须用 Approx！
}

TEST_CASE("Anime getters 返回正确字段")
{
	Anime a("名字A", "作者B", "评论C", 7.0f);
	CHECK(a.getName() == "名字A");
	CHECK(a.getAuthor() == "作者B");
	CHECK(a.getDescription() == "评论C");
}