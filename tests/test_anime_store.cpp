#include "AnimeStore.h"
#include "doctest.h"
#include <fstream>
#include <cstdio>
#include <stdexcept>

// 测试专用：写一个含 2 条记录的合法数据文件
static void writeDataFile(const std::string& path)
{
	std::ofstream fout(path);
	fout << "番剧A\n作者A\n评论A\n8.5\n";
	fout << "番剧B\n作者B\n评论B\n9.5\n";
}

TEST_CASE("AnimeStore：不存在的文件 → 空馆藏")
{
	std::remove("test_nonexist.txt");
	AnimeStore store("test_nonexist.txt");
	CHECK(store.getCount() == 0);
}

TEST_CASE("AnimeStore：保存→重新加载 往返一致")
{
	const std::string path = "test_roundtrip.txt";
	writeDataFile(path);                 // 造数据文件
	AnimeStore store(path);              // 构造时加载
	CHECK(store.getCount() == 2);
	CHECK(store.getAt(0).getName() == "番剧A");
	CHECK(store.getAt(1).getRate() == doctest::Approx(9.5f));

	store.saveToFile();                  // 存回

	AnimeStore reloaded(path);           // 重新加载，验证格式没写坏
	CHECK(reloaded.getCount() == 2);
	CHECK(reloaded.getAt(0).getAuthor() == "作者A");
	CHECK(reloaded.getAt(1).getName() == "番剧B");
	std::remove(path.c_str());           // 清理测试文件
}

TEST_CASE("AnimeStore：remove 删除指定项")
{
	const std::string path = "test_remove.txt";
	writeDataFile(path);
	AnimeStore store(path);
	store.remove(1);                     // 删第二项
	CHECK(store.getCount() == 1);
	CHECK(store.getAt(0).getName() == "番剧A");
	std::remove(path.c_str());
}

TEST_CASE("AnimeStore：reset 清空")
{
	const std::string path = "test_reset.txt";
	writeDataFile(path);
	AnimeStore store(path);
	store.reset();
	CHECK(store.getCount() == 0);
	std::remove(path.c_str());
}

TEST_CASE("AnimeStore：getAt 越界抛异常")
{
	const std::string path = "test_throw.txt";
	writeDataFile(path);
	AnimeStore store(path);
	CHECK_THROWS_AS(store.getAt(99), std::out_of_range);
	std::remove(path.c_str());
}