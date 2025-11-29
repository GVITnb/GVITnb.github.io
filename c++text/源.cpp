#include<easyx.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

IMAGE img_bk[1];
IMAGE img_me[1];

// 全局定义流星结构体
struct Meteor {
    int x;
    int y;
    int speed;
};

// 加载图片函数：修正图片加载逻辑，区分背景和流星图片
void loadImg() {
    loadimage(img_bk + 0, L"./images/bj.png", getwidth(), getheight());
    loadimage(img_me + 0, L"./images/lx.png", 25, 25);  // 加载流星图片并指定尺寸
}

// 流星初始化函数
void Meteor_init(Meteor* pthis, int x, int y, int speed) {
    pthis->x = rand() % 1100 - 300;
    pthis->y = rand() % 840 - 300;
    pthis->speed = speed;
}

// 流星绘制函数
void meteor_draw(Meteor* pthis) {
    putimage(pthis->x, pthis->y, img_me + 0, SRCPAINT);
}

// 流星更新函数（处理移动和重置）
void meteor_update(Meteor* pthis) {
    pthis->x += pthis->speed;
    pthis->y += pthis->speed;
    // 超出屏幕则重置位置
    if (pthis->x > getwidth() || pthis->y > 550) {
        pthis->x = rand() % 1100-300;
        pthis->y = rand() % 840-300;
    }
}

// 欢迎界面逻辑（可根据需求补充）
void welcome() {
    // 若有欢迎界面逻辑可在此添加
}

int main() {
    srand((unsigned int)time(NULL));
    initgraph(1200, 800);
    setbkmode(TRANSPARENT);
    loadImg();
    welcome();  // 调用欢迎界面函数

    // 创建并初始化流星对象
    Meteor m;
    Meteor meteors[30];
    for (int i = 0; i < 30; i++) {
        Meteor_init(meteors+i, rand()%getwidth(),rand()%getheight(), rand()%2+1);
    }
    

    while (true) {

        BeginBatchDraw();
        putimage(0, 0, img_bk + 0);  // 绘制背景

        // 绘制文字
        settextstyle(35, 0, L"宋体");
        settextcolor(WHITE);
        outtextxy(450, 400, L"");
        outtextxy(600, 400, L"");

        // 绘制并更新流星
        for (int i = 0; i < 30; i++) {
            meteor_update(meteors + i);
            meteor_draw(meteors+i);
            
        }
        EndBatchDraw();
       

        Sleep(10);  

        }closegraph();
    }

   

