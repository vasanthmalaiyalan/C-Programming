## இதை compare பண்ணிப் பார்ப்போம்
 

| Situation | Correct | Explanation |
| --------- | ------- | ----------- |
| `int *p = &amp;i;` | ✅ | Pointer assign செய்ய normal |
| `printf("%p", &amp;i);` | ⚠️ Works but warning வரலாம் | Compiler strict ஆக இருந்தால் warning |
| `printf("%p", (void*)&amp;i);` | ✅ Perfect standard | C standard-க்கு fully correct |

