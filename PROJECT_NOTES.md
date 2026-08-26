# Anime_Archive_Z 项目日志

> 本文件是"跨设备共享记忆"：每台电脑/每个账户开工前先读它，收工后更新它，然后提交推送到 GitHub。

## 一句话简介
控制台番剧档案管理（增删/展示/排名/手动备份 + 文件持久化），处于"现代化改造"阶段。

## 协作约定
- 本机（VS）+ 另一台电脑（VS Code）经 GitHub 协作，远程已统一为 HTTPS。
- 所有代码改动由本人亲自完成，AI 助手只负责指路、审查与解释。
- 调试以实际运行为准，不盲信任何"口头诊断"。

## 当前状态（今天更新）
### 已完成
- [x] GitHub 同步修复：SSH → HTTPS（本机 22 端口被墙）
- [x] P0#1 主循环条件修复（choice != 0）
- [x] P0#2 remove 越界修复（校验上移到 UI 层）
- [x] P0#3 输入失败检查 + 退出循环重构（while(true) + break，修掉"C++11 失败置 0 + do-while continue"组合坑）
- [x] 保存/备份拆分：saveToFile 纯保存(bool)、backup() 流复制、析构不再做 I/O、main 显式保存
- [x] 编码修复：main.cpp 已存为 UTF-8 带签名

### 待办（下次按顺序）
- [ ] 最后确认一次：输 a 回菜单、输 0 退出（若还没测）
- [ ] 项目属性加编译开关 /utf-8（VS Code 存的无 BOM 文件需要）
- [ ] add() 评分输入校验（非数字评分会污染数据）
- [ ] 严格输入校验：拒绝 "0abc" 这类 0 开头的部分匹配
- [ ] UI.cpp：default 的死代码 std::cin.ignore() 删除、"啥杯"清理
- [ ] 工程化：CMake、单元测试、README、目录整理
- [ ] P2 现代 C++：getters 返回 const&、菜单 enum class、include what you use、构造初始化列表顺序
- [ ] 另一台电脑的 VS Code HTTPS 认证问题（认证失败类，等人在那边再处理）

## 关键决定记录
- SSH → HTTPS（本机 22 端口被墙，新账户无 SSH 密钥）
- 保存/备份职责拆分；析构函数不做 I/O；main 退出前显式保存
- 输入循环改为 while(true) + 显式 break，退出信号 choice == 0
- 源码编码统一 UTF-8

## 今日踩坑（教科书级，反复看）
1. C++11 起：`cin >> int` 提取失败时，变量被写成 0（不是保持不变）
2. do-while 里 `continue` 跳到条件求值，不是循环体开头
3. Windows 上 std::rename 不覆盖已存在的目标文件
4. MSVC 对无 BOM 源码默认按系统编码（GBK）读 → 中文乱码，用 /utf-8 统一

## 常用命令备忘
- 结束一天：更新本文件 → git add PROJECT_NOTES.md → git commit -m "docs: 更新项目日志" → git push