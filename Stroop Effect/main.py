import pygame
import sys
import traceback
from random import *
from pygame.locals import *

testAmount=int(20)

# show words       
def textShow(size,targetText,pos_x,pos_y):
    result_font = pygame.font.Font("./Font/kaiu.ttf", size)
    result_text = result_font.render(targetText, True, (0,0,0))
    resultRect = result_text.get_rect()
    resultRect.center = (pos_x,pos_y)
    screen.blit(result_text, resultRect)

# rule
def firstSurface():
    running = False
    begin = False

    while not begin:
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
            elif event.type == KEYDOWN:
                running = True
                begin = True
                main(running)
        
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
        
        text_begin = "按下 *任意鍵* [開始]"
        textShow(16,text_begin,width/2,(height/2+260))
        
        pygame.display.flip()

#测试程序
def main(running):
    words = ["紅 色","綠 色","黃 色","黑 色","紫 色","藍 色","橘 色","棕 色","灰 色","粉 红","口 紅","樹","草 原","蘋 果","幸運草","紅寶石","綠 豆","玫 瑰","檸 檬","西瓜皮"]
    
    word_font = pygame.font.Font("./Font/kaiu.ttf", 288)
    
    times = {}
    corrects = {}
    
    initTime = pygame.time.get_ticks()
    lastTime = pygame.time.get_ticks()
    newTime = pygame.time.get_ticks()
    everyTime = 0 #平均时间
    
    sequence = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
    shuffle(sequence)
    
    # color
    colors = []
    GREEN = (0,255,0)
    colors.append(GREEN)
    RED = (255,0,0)
    colors.append(RED)
    color = choice(colors)
    # determine correct or not
    correct = True
    # count 
    number = 0
    
    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
            elif event.type == KEYDOWN:
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
                        color = choice(colors)
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
                        color = choice(colors)
        # white bg color       
        screen.fill((255,255,255))
        lastTime = newTime
        if number < testAmount:
            word_text = word_font.render(words[sequence[number]-1], True, color)
            wordRect = word_text.get_rect()
            wordRect.center = (width/2,height/2)
            screen.blit(word_text, wordRect)   
        elif number == testAmount:
            tempText = ""
            with open("./File/record.txt", "w") as f:
                for i in words:
                    tempText += (i + "：" + str(times[i]) + "毫秒，判斷是否正確：" + str(corrects[i]) + "\n")
                everyTime = (newTime - initTime)/testAmount
                tempText += ("平均答題時間為：" + str(everyTime) + "毫秒。")
                f.write(tempText)
            number += 1
        else:
            count_num = 0
            for i in corrects.values():
                if i == False:
                    count_num += 1
            resultText = "平均答題時間為：" + str(everyTime) + "毫秒，錯誤個數為：" + str(count_num) + "個" 
            textShow(54,resultText,width/2,height/2)
        
        pygame.display.flip()
    
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