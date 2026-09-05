#include "Anime.h"
#include "doctest.h"

TEST_CASE("Anime 构造器：非法评分被钳制为 0")
{
    Anime a("名", "作者", "描述", 99.0f);
    CHECK(a.getRate() == 0.0f);
}
