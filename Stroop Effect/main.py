import pygame
import sys
import traceback
from random import *
from pygame.locals import *

# show words       
def textShow(size,targetText,pos_x,pos_y):
    result_font = pygame.font.Font("./Font/kaiu.ttf", size, encoding='UTF-8')
    result_text = result_font.render(targetText, True, (0,0,0))
    resultRect = result_text.get_rect()
    resultRect.center = (pos_x,pos_y)
    screen.blit(result_text, resultRect)

# rule
def firstSurface():
    running = False
    begin = False

    while not begin:
        screen.fill((255,255,255))
        text_caption = "STROOP TEST !"
        textShow(96,text_caption,width/2,(height/2-260))
        
        text_rule1 = "規則"
        textShow(48,text_rule1,width/2,(height/2-120))
        text_rule2 = "大聲讀出文字，並判斷該文字的顏色 [字體顏色]"
        textShow(28,text_rule2,width/2,(height/2-20))
        text_rule3 = "如果字體為“紅色”，則按下 [R] 鍵"
        textShow(28,text_rule3,width/2,(height/2+30))
        text_rule4 = "如果字體為“綠色”，則按下 [G] 鍵"
        textShow(28,text_rule4,width/2,(height/2+80))
        text_begin = "請用滑鼠按一下畫面再按下 *任意鍵* [開始]"
        textShow(32,text_begin,width/2,(height/2+260))
        
        pygame.display.flip()
        event = pygame.event.wait()
        if event.type == QUIT:
            sys.exit()
        elif event.type == KEYDOWN:
            running = True
            begin = True
            main(running)

# test process
def main(running):
    word_font = pygame.font.Font("./Font/kaiu.ttf", 288, encoding='UTF-8')
    testAmount=int(10)
    GREEN = (0,255,0)
    RED = (255,0,0)
    stage_words = [
                    ["口 紅","樹","草 原","蘋 果","幸運草","紅寶石","綠 豆","玫 瑰","檸 檬","西瓜皮"],
                    ["紅 色","綠 色","黃 色","黑 色","紫 色","藍 色","橘 色","棕 色","灰 色","粉 紅"],
                    ["口 紅","藍 色","草 原","紅 色","幸運草","橘 色","綠 豆","西瓜皮","綠 色","玫 瑰"]
                ]
    words_color = [
                    [RED,GREEN,GREEN,RED,GREEN,RED,GREEN,RED,GREEN,GREEN],
                    [GREEN,RED,RED,GREEN,RED,RED,GREEN,RED,GREEN,GREEN],
                    [GREEN,GREEN,RED,GREEN,RED,RED,GREEN,RED,RED,GREEN]
                ]
    
    for stage in range (1,4):
        running = True
        begin = False
        while not begin:
            screen.fill((255,255,255))
            numberOfStage = "第 " + str(stage) + " 階段"
            textShow(96,numberOfStage,width/2,height/2)
            text_begin = "按下 *空白鍵* [開始]"
            textShow(32,text_begin,width/2,(height/2+260))
            pygame.display.flip()
            event = pygame.event.wait()
            if event.type == QUIT:
                sys.exit()
            elif event.type == KEYDOWN and event.key == pygame.K_SPACE:
                running = True
                begin = True
            
            
        
        times = {}
        corrects = {}

        initTime = pygame.time.get_ticks()
        lastTime = pygame.time.get_ticks()
        newTime = pygame.time.get_ticks()
        everyTime = 0 # 平均時間

        sequence = [1,2,3,4,5,6,7,8,9,10]
        shuffle(sequence)
        
        words = stage_words[stage-1]

        # count
        number = 0
        # color
        colors = words_color[stage-1]
        # determine correct or not
        correct = True
        finished_stage = False
        
        while running:
            # white bg color 
            screen.fill((255,255,255))
            if finished_stage == False:
                color = colors[sequence[number]-1]
            if number < testAmount:
                word_text = word_font.render(words[sequence[number]-1], True, color)
                wordRect = word_text.get_rect()
                wordRect.center = (width/2,height/2)
                screen.blit(word_text, wordRect)
                pygame.display.flip()
            event = pygame.event.wait()
            if event.type == QUIT:
                sys.exit()
            elif event.type == KEYDOWN and finished_stage == False:
                if number < testAmount:
                    if event.key == K_r:
                        newTime = pygame.time.get_ticks()
                        differTime = newTime - lastTime
                        if color == RED:
                            correct = True
                        else:
                            correct = False
                        times[words[sequence[number]-1]] = differTime
                        corrects[words[sequence[number]-1]] = correct
                        number += 1
                    if event.key == K_g:
                        newTime = pygame.time.get_ticks()
                        differTime = newTime - lastTime
                        if color == RED:
                            correct = False
                        else:
                            correct = True
                        times[words[sequence[number]-1]] = differTime
                        corrects[words[sequence[number]-1]] = correct
                        number += 1
            lastTime = newTime
            if number == testAmount:
                tempText = ""
                correct_cnt = int(0)
                if stage == 1:
                    with open("./File/record.txt", "w", encoding='UTF-8') as f:
                        tempText += ("!!! Google 表單連結: https://reurl.cc/DylX9e !!!\n\n")
                        tempText += ("第 1 階段測驗結果如下:\n")
                        for i in words:
                            if corrects[i] == True:
                                correct_cnt += 1
                        everyTime = (newTime - initTime)/testAmount
                        tempText += ("平均答題時間為：" + str(everyTime) + "毫秒。\n" "答對率為: " + str((correct_cnt/10)*100) + " %\n\n")
                        f.write(tempText)
                elif stage == 2:
                    with open("./File/record.txt", "a", encoding='UTF-8') as f:
                        tempText += ("第 2 階段測驗結果如下:\n")
                        for i in words:
                            if corrects[i] == True:
                                correct_cnt += 1
                        everyTime = (newTime - initTime)/testAmount
                        tempText += ("平均答題時間為：" + str(everyTime) + "毫秒。\n" "答對率為: " + str((correct_cnt/10)*100) + " %\n\n")
                        f.write(tempText)
                else:
                    with open("./File/record.txt", "a", encoding='UTF-8') as f:
                        tempText += ("第 3 階段測驗結果如下:\n")
                        for i in words:
                            if corrects[i] == True:
                                correct_cnt += 1
                        everyTime = (newTime - initTime)/testAmount
                        tempText += ("平均答題時間為：" + str(everyTime) + "毫秒。\n" "答對率為: " + str((correct_cnt/10)*100) + " %\n")
                        tempText += ("\n!!! 請將以下實驗結果「全部」貼上 Google 表單最後一題 !!!\n\n")
                        for i in words:
                            tempText += (i + "：" + str(times[i]) + "毫秒，判斷是否正確：" + str(corrects[i]) + "\n")
                        tempText += ("\n")
                        f.write(tempText)
                number += 1
                finished_stage = True
            elif number > testAmount:
                count_num = 0
                for i in corrects.values():
                    if i == False:
                        count_num += 1
                begin = False
                if stage <= 2:
                    resultText = "平均答題時間為：" + str(everyTime) + "毫秒，錯誤個數為：" + str(count_num) + "個" 
                    textShow(54,resultText,width/2,height/2)
                    text_begin = "按下 *空白鍵* 繼續下一個階段"
                    textShow(32,text_begin,width/2,(height/2+260))
                    pygame.display.flip()
                    while not begin:
                        event = pygame.event.wait()
                        if event.type == QUIT:
                            sys.exit()
                        elif event.type == KEYDOWN and event.key == pygame.K_SPACE:
                            begin = True
                else:
                    resultText = "平均答題時間為：" + str(everyTime) + "毫秒，錯誤個數為：" + str(count_num) + "個" 
                    textShow(54,resultText,width/2,height/2)
                    text_begin = "按下 *空白鍵* 結束程式並至 File 資料夾察看結果"
                    textShow(32,text_begin,width/2,(height/2+260))
                    pygame.display.flip()
                    while not begin:
                        event = pygame.event.wait()
                        if event.type == QUIT:
                            sys.exit()
                        elif event.type == KEYDOWN and event.key == pygame.K_SPACE:
                            begin = True
                running = False
    
if __name__ == "__main__":
    try:
        pygame.init()

        bg_size = width, height = 1280, 720
        screen = pygame.display.set_mode(bg_size)
        pygame.display.set_caption("Stroop Test")
        
        firstSurface()


    except SystemExit:
        pass
    except:
        traceback.print_exc()
        pygame.quit()
        input()