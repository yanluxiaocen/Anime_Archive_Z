\# Anime\_Archive\_Z 项目日志



> 本文件是"跨设备共享记忆"：每台电脑/每个账户开工前先读它，收工后更新它，然后提交推送到 GitHub。



\## 一句话简介

控制台番剧档案管理（增删/展示/排名 + 文件持久化），当前处于"现代化改造"阶段。



\## 协作约定

\- 本机（VS）+ 另一台电脑（VS Code）经 GitHub 协作，远程已全部统一为 HTTPS（443 端口）。

\- 所有代码改动由本人亲自完成，AI 助手只负责指路、审查与解释。



\## 当前状态（2025-XX-XX 更新）

\- ✅ GitHub 同步已修复（SSH → HTTPS）

\- ⏳ 待办：P0 正确性 bug 三个（main 循环恒真 / remove 越界 / 输入流混乱）

\- ⏳ 待办：工程化（CMake、单元测试、README、目录整理）

\- ⏳ 待办：现代 C++ 风格（const 引用、enum class、include what you use）



\## 关键决定记录

\- \[日期] 远程从 SSH 切到 HTTPS（本机 22 端口被墙）



\## 下一步（只做这一件）

\- \[ ] 修复 P0 bug #1：main() 的 do-while 循环条件



\## 常用命令备忘

\- 推送到 GitHub：`git push`

\- 查看远程：`git remote -v`

