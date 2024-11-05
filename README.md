# 🌟 BRAINRUNNER - THE ULTIMATE BRAINFUCK COMPILER / RUNNER! 🌟

## 🚀 How to Use

### 📁 First Way: Put All .bf Files in Brainrunner Delivery
You just have to **copy/paste** and write your Brainfuck scripts into the Brainrunner folder, or specify the path and then run:

```shell
./brainrunner.sh path_to_file.bf
```

### 🔗 Second Way: Create a Symlink
To create a symlink that allows you to run Brainfuck scripts from anywhere, use the following commands:

```shell
cd /usr/local/bin
ln -s PATH_TO_CLONED_REPO/brainrunner.sh brainrunner
```

Now, you can run your Brainfuck scripts like this:

```shell
brainrunner path_to_file.bf
```

## ✅ Works
- **Translates** .bf files into .c files
- **Runs** .bf files

## ❌ Doesn't Work
- Just **translates** without running
- **Brainfuck extensions** (like functions)
- **Epitech coding style**

## 🙏 Thank You for Visiting
#### ✍️ Gauthier Malfilatre
