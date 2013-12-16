pushd %~dp0
robocopy "\\AVALON\E$\Project\WaffleProject\WaffleNightly\Component" "%CD%\Component" /E
robocopy "\\AVALON\E$\Project\WaffleProject\WaffleNightly\TestCase" "%CD%\TestCase" /E
robocopy "\\AVALON\E$\Project\WaffleProject\WaffleNightly" "%CD%" Waffle.vbs