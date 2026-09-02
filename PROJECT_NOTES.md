# Anime_Archive_Z 项目日志

> 本文件是"跨设备共享记忆"：每台电脑/每个账户开工前先读它，收工后更新它，然后提交推送到 GitHub。

## 一句话简介
控制台番剧档案管理（增删/展示/排名/手动备份/重置 + 文件持久化），处于"现代化改造"阶段。

## 协作约定
- VS2022 主力机 + VS Code 外出机 经 GitHub 协作，远程已统一为 HTTPS。
- 所有代码改动由本人亲自完成，AI 助手只负责指路、审查与解释。
- 调试以实际运行为准，不盲信任何"口头诊断"。

## 当前状态（今天更新）
### 已完成
- [x] GitHub 同步修复：SSH → HTTPS（22 端口被墙）；**VS Code 机推送依赖 Steam++ GitHub 加速**（关掉后 git 直连 443 超时）
- [x] git SSL 证书问题：`http.sslBackend schannel`（OpenSSL 无法验证 Steam++ 加速节点的证书链）
- [x] P0 全部清零：主循环条件 / remove 越界 / 输入失败检查 + 退出循环重构 / 评分校验
- [x] 保存/备份拆分：saveToFile 纯保存(bool)、backup() 流复制、析构不再做 I/O、main 显式保存
- [x] 编码统一 UTF-8（/utf-8 早已设置）
- [x] 严格输入校验（整行 + istringstream 完整解析）**覆盖全部输入点**：主菜单 / add 评分 / remove 编号（此前只改了主菜单入口，add/remove 内部仍是 cin >>，会吞 "3.5abc" 污染后续输入）
- [x] 删除模式修复：index==0 退出不再残留回车、删除成功增加"已删除"反馈
- [x] 重置馆藏：reset() + case 6，y/n 确认 + 清空前自动备份（破坏性操作安全设计）
- [x] 菜单 enum class：MenuChoice 枚举、switch 全改、static_cast 桥接、Exit 显式判断
- [x] VS Code 调试产物统一：exe 固定输出 Anime_Archive_Z.exe（tasks/launch 各改一行），清理多余 UI.exe/AnimeStore.exe
- [x] c_cpp_properties.json 加 excludePath（x64/Debug/Release/.git/.cph/build）
- [x] 数据文件退出版本控制：.gitignore 忽略 Anime.txt/*.bak 并解跟踪（两机数据各自独立，不再 pull 冲突）
- [x] P2 三件套：getters 返回 const&、构造初始化列表顺序、include 瘦身（cstdio 已删）
- [x] VS Code 用户设置：files.encoding=utf8 显式化；[cpp]/[c] 保存不自动格式化（防 clang-format 默认风格重排 Tab 代码）

### 待办（下次按顺序）
- [ ] 菜单文案补"0.退出"（功能早已有，文案搁置中——之前日志误记为已完成，实际未补）
- [ ] 全量回归测试：输入校验（0abc/3.5abc 全拒绝、删除 0 退出、连续删除）/ 重置馆藏 / enum class 菜单
- [ ] 工程化（预估 5–6h，分 2–3 周）：目录整理（三层同名嵌套 Anime_Archive_Z/Anime_Archive_Z/Anime_Archive_Z）→ CMake（全新领域，重头）→ 单元测试 doctest → README+截图
- [ ] 可选加分：Qt + SQLite 桌面版（约 10–15h）

## 关键决定记录
- SSH → HTTPS（22 端口被墙，新账户无 SSH 密钥）
- VS Code 机访问 GitHub 依赖 Steam++（Watt Toolkit）加速，推送前先开加速
- git SSL 后端改 schannel：Steam++ 节点证书链 OpenSSL 验证报 "unable to get local issuer certificate (20)"
- 保存/备份职责拆分；析构函数不做 I/O；main 退出前显式保存
- 输入循环改为 while(true) + 显式 break，退出信号 choice == 0
- 输入校验统一"整行读取 + istringstream 完整解析"：cin >> 只吃数字前缀，必须再查 `(iss >> std::ws).eof()`
- 破坏性操作前先确认 + 自动备份（重置馆藏先备份再清空）
- 菜单引入 enum class MenuChoice，告别魔法数字
- VS Code 调试输出固定 exe 名：tasks 默认模板用 ${fileBasenameNoExtension} 命名，在哪个文件按 F5 就生成同名 exe；多文件项目应固定为 main 文件名
- 数据文件 Anime.txt/*.bak 不提交：运行时产物，两机数据独立，提交会导致 pull 冲突
- 源码编码统一 UTF-8

## 踩坑库（教科书级，反复看）
1. C++11 起：数值提取失败时，目标变量被写成 0（int/float 都是，不是保持不变）
2. do-while 里 `continue` 跳到条件求值，不是循环体开头
3. Windows 上 std::rename 不覆盖已存在的目标文件
4. MSVC 对无 BOM 源码默认按系统编码（GBK）读 → 中文乱码，用 /utf-8 统一
5. 改了代码没 Ctrl+S，磁盘上还是旧文件——排查"改了没反应"前先检查保存
6. `cin >> int` 只吃数字前缀："0abc" 会解析成 0——要"整行合法"必须读整行再完整校验
7. 功能与菜单文案同步：退出功能早就有了，菜单却一直没写"0.退出"
8. 浏览器能上 GitHub ≠ git 能上：浏览器走代理/加速，git 直连——Steam++ 一关就 443 超时
9. OpenSSL 报 "unable to get local issuer certificate (20)" → 换 `http.sslBackend schannel`（用 Windows 证书库）
10. PowerShell `Get-Content` 默认按 GBK 读 UTF-8 无 BOM 文件 → 校验 JSON 误报 invalid，加 `-Encoding UTF8`
11. VS Code "生成活动文件"任务：输出 `${fileBasenameNoExtension}.exe` 会在每个源文件按 F5 时生成同名 exe（内容相同全是完整程序），多文件项目应固定为 main 文件名

## 常用命令备忘
- 结束一天：更新本文件 → git add PROJECT_NOTES.md → git commit -m "docs: 更新项目日志" → git push
- VS Code 机推送前：先开 Steam++ GitHub 加速（网络钥匙，关了就超时）
