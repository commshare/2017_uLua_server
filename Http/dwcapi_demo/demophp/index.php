<?php
    header("Content-type: text/html; charset=gb2312");

    include_once 'op.php';
   
    function outputInfo($tipInfo, $content)
    {
        echo $tipInfo; 
        echo $content, '<br/>';
    }
    
    function queryMoneyChange($mgr, $playerAcc)
    {
        $retStr = $mgr->queryPlayerMoneyChange($playerAcc, 0, 0, "2016-06-01 00:00:00", "2016-07-27 23:59:59");
        outputInfo("��һ��ұ仯���1--------------", $retStr);
        
        $retStr = $mgr->queryPlayerMoneyChange($playerAcc, 1, 100, "2016-06-01 00:00:00", "2016-07-27 23:59:59");
        outputInfo("��һ��ұ仯���2--------------", $retStr);
    }
    
    function queryWinLose($mgr, $playerAcc)
    {
        $retStr = $mgr->queryPlayerWinLose($playerAcc, 0, 0, "2016-06-01", "2016-07-27");
        outputInfo("�����Ӯ���1--------------", $retStr);
        
        $retStr = $mgr->queryPlayerWinLose($playerAcc, 1, 100, "2016-06-01", "2016-07-27");
        outputInfo("�����Ӯ���2--------------", $retStr);
    }
    
    function updatePwd($mgr, $playerAcc)
    {
        $retStr = $mgr->updatePlayerPwd($playerAcc, "123456", "654321");
        outputInfo("�޸�������1----------------------------", $retStr);
    
        $retStr = $mgr->updatePlayerPwd($playerAcc, "654321", "123456");
        outputInfo("�޸�������2----------------------------", $retStr);
    }
    
    function queryWinLoseSum($mgr)
    {
        $retStr = $mgr->queryWinLoseSum("2016-05-01", "2016-05-08");
        outputInfo("��Ӯ�ܺ�1----------------------------", $retStr);
    
        $retStr = $mgr->queryWinLoseSum("2016-05-08", "2016-06-08");
        outputInfo("��Ӯ�ܺ�2----------------------------", $retStr);
    }
    
    function playerOp($mgr, $playerAcc)
    {
        $retStr = $mgr->playerOp($playerAcc, 0);
        outputInfo("ͣ����----------------------------", $retStr);
    
        $retStr = $mgr->playerOp($playerAcc, 1);
        outputInfo("�����----------------------------", $retStr);
    }
    
    // �ٶ������GM��̨�˺�
    $gmAcc = "ybiaoCNY123z";
    // �ٶ������GM��̨�˺�����
    $gmPwd = "123456";
    // �ٶ������GM��̨������Կ
    $devKey = "fa4c1529f25e426ea489a88637178d36";

    $mgr = new OpMgr($gmAcc, $gmPwd, $devKey);
    
    // ����˺Ź��ɣ�ǰ׺+�˺���
    $playerAcc = "123zyb003";
    
    $retStr = "";
    
    // �������
    $retStr = $mgr->createPlayer($playerAcc, "abc123");
    outputInfo("������ҽ��--------------", $retStr);
    
    $retStr = $mgr->playerSaveMoney($playerAcc, 500, Tool::genGuid(), "");
    outputInfo("��Ҵ����--------------", $retStr);
    
    $retStr = $mgr->playerDrawMoney($playerAcc, 500, Tool::genGuid(), "");
    outputInfo("��������--------------", $retStr);
   
    $retStr = $mgr->queryPlayerTradingRecord($playerAcc, 0, 0, 0, "2016-06-01 00:00:00", "2016-07-31 23:59:59");
    outputInfo("��Ҵ�ȡ����1--------------", $retStr);
    
    $retStr = $mgr->queryPlayerTradingRecord($playerAcc, 2, 1, 9, "2016-06-01 00:00:00", "2016-07-31 23:59:59");
    outputInfo("��Ҵ�ȡ����2--------------", $retStr);
    
    $retStr = $mgr->queryPlayerInfo($playerAcc);
    outputInfo("��ѯ�����Ϣ���--------------", $retStr);
    
    $retStr = $mgr->queryPlayerOnline($playerAcc);
    outputInfo("��ѯ����Ƿ�����--------------", $retStr);
    
    $retStr = $mgr->logoutPlayer($playerAcc, 600);
    outputInfo("�ǳ����--------------", $retStr);
    
    $retStr = $mgr->clearLoginFailed($playerAcc);
    outputInfo("������ҵ�¼ʧ�ܴ������--------------", $retStr);
    
    $retStr = $mgr->unlockPlayer($playerAcc);
    outputInfo("������ҽ��-------------", $retStr);
    
    queryMoneyChange($mgr, $playerAcc);
    
    queryWinLose($mgr, $playerAcc);
    
    updatePwd($mgr, $playerAcc);
    
    queryWinLoseSum($mgr);
    
    playerOp ($mgr, $playerAcc);
?>





























