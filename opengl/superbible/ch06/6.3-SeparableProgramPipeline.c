//
// 摘自 OpenGL SuperBible 第六版
// 
// Configuring a separable program pipeline
// 
// 2015-03-16 etond
//

// 创建一个顶点着色器
GLuint vs = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vs, 1, vs_source, NULL);
glCompileShader(vs);

// 创建顶点着色器对应的program
GLuint vs_program = glCreateProgram();
glAttachShader(vs_program, vs);
// 设置分离参数，表示分离
glProgramParameteri(vs_program, GL_PROGRAM_SEPARABLE, GL_TRUE);
glLinkProgram(vs_program);

// 片段着色器
GLuint fs = glCreateProgram(GL_FRAGMENT_SHADER);
glShaderSource(fs, 1, fs_source, NULL);
glCompileShader(fs);

// 创建顶点着色器对应的program
GLuint fs_program = glCreateProgram();
glAttachShader(fs_program, fs_source);
// 设置分离参数，表示分离
glProgramParameteri(fs_program,  GL_PROGRAM_SEPARABLE, GL_TRUE);
glLinkProgram(fs_program);


// 新建一个管线
GLuint program_pipeline;
glGenProgramPipelines(1, &program_pipeline);

// 设置顶点着色器程序
glUseProgramStages(program_pipeline, GL_VERTEX_SHADER_BIT, vs_program);
// 设置片段着色器程序
glUseProgramStages(program_pipeline, GL_FRAGMENT_SHADER_BIT, fs_program);
