# Example.Externals.Vcpkg

Практическая демонстрация способов подключения библиотек, собранных через 
[Externals.Vcpkg](https://github.com/Unicornum/Externals.Vcpkg.git).

### Подключение готовых сборок через Externals.props

- Скачать архив из релизов [Externals.Vcpkg](https://github.com/Unicornum/Externals.Vcpkg/releases),
распаковать его в папку Externals (в корне решения) с заменой файлов.

> Для замены на библиотеки других версий скачать нужную версию архива
> и просто распаковать туда же с заменой файлов.

### Подключение через Directory.Build.props

- Скачать архив из релизов [Externals.Vcpkg](https://github.com/Unicornum/Externals.Vcpkg/releases),
распаковать его в **любую** папку и выполнить в этой папке cmd команду

```
setx UNICORNUM_EXTERNALS_SDK_V002 %CD%
```

- В корень решения добавить файл Directory.Build.props, содержащий

```
<Project>
 <Import Project="$(UNICORNUM_EXTERNALS_SDK_V002)\Externals.props" />
</Project>
```

это автоматически даст доступ всем проектам решения к собранным библиотекам 
именно этой версии.

> Для замены на библиотеки других версий скачать нужную версию архива,
> повторить процедуру регистрации с другим именем версии UNICORNUM_EXTERNALS_SDK_VXXX
> и заменить макрос в Directory.Build.props.

> [22.11.2024] Подключение к Directory.Build.props и Directory.Build.targets
> файлов из vcpkg\scripts\buildsystems\msbuild не работает, т.к. в результате 
> пути к include идут к папке x64-windows, а не x64-windows-static. Кроме того,
> там нет путей для Android проектов.

### Подключения для автоматической сборки

- Добавить [Externals.Vcpkg](https://github.com/Unicornum/Externals.Vcpkg.git) 
репозиторию проекта как субмодуль со ссылкой на нужный tag.
- Подключить Externals.props ко всем проектам из папки субмодуля.

> Библиотеки будут собраны один раз при первой сборке одного из проектов.

> Для замены на библиотеки других версий переключить субмодуль на другой tag
> и очистить папку субмодуля от неверсированных файлов.

### Глобальное встраивание в Visual Studio

> [22.11.2024] Заставить работать эти способом не удалось, т.к. ссылки на include 
> в результате идут к папке x64-windows и сборки x64-windows-static игнорируются.
> Нужно явно задавать параметр --triplet?

- Скачать архив из релизов Externals.Vcpkg (TODO: Добавить ссылку),
распаковать его в любое место и выполнить в папке команду

```
vcpkg integrate install
```

Для удаления интеграции выполнить **vcpkg integrate remove**.
