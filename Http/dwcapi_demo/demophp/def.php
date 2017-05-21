<?php
    class CC
    {
        //windows�µ�PHP��ֻ��Ҫ��php.ini�а�extension=php_openssl.dllǰ��� ; ɾ�����Ϳ�������https����
        //public static $SERVER_DOMAIN = "https://localhost:9439";
        
        public static $SERVER_DOMAIN = "http://localhost:9439";
        
        // �������
        public static $URL_CREATE_PLAYER = "/appaspx/CreatePlayer.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&playerPwd=%s&sign=%s";
        
        // ������ң���ϴ��ȣ�����
        public static $URL_CREATE_PLAYER1 = "/appaspx/CreatePlayer.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&playerPwd=%s&washRatio=%d&aliasName=%s&sign=%s";
        
        // ��Ҵ��
        public static $URL_SAVE_MONEY = "/appaspx/PlayerSaveMoney.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&score=%d&sign=%s&userOrderId=%s&apiCallBack=%s";
        
        // ���ȡ��
        public static $URL_DRAW_MONEY = "/appaspx/PlayerDrawMoney.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&score=%d&sign=%s&userOrderId=%s&apiCallBack=%s";
        
        // ��Ҵ�����¼
        public static $URL_PLAYER_TRADING_RECORD = "/appaspx/QueryPlayerTradingRecord.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&curPage=%d&countEachPage=%d&startTime=%s&endTime=%s&opType=%d&sign=%s";
        
        // ��ѯ�����Ϣ
        public static $URL_QUERY_PLAYER_INFO = "/appaspx/QueryPlayerInfo.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&sign=%s";
        
        // ��ѯ����Ƿ�����
        public static $URL_QUERY_PLAYER_ONLINE = "/appaspx/QueryPlayerOnline.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&sign=%s";
        
        // �ǳ����
        public static $URL_LOGOUT_PLAYER = "/appaspx/LogoutPlayer.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&forbidTime=%d&sign=%s";
        
        // ��¼ʧ�ܴ�����0
        public static $URL_CLEAR_LOGIN_FAILED = "/appaspx/ClearLoginFailed.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&sign=%s";
        
        // �������
        public static $URL_UNLOCK_PLAYER = "/appaspx/UnlockPlayer.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&sign=%s";
        
        // ���������Ϣ
        public static $URL_UPDATE_PLAYER_INFO = "/appaspx/UpdatePlayerInfo.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&sign=%s";
        
        // ��ѯ�������Ϸ�ڵĻ��ұ仯��¼
        public static $URL_PLAYER_MONEY_CHANGE = "/appaspx/QueryPlayerMoneyChange.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&curPage=%d&countEachPage=%d&startTime=%s&endTime=%s&sign=%s";
        
        // ��ѯ�����Ӯͳ�Ƽ�¼
        public static $URL_PLAYER_WIN_LOSE = "/appaspx/QueryPlayerWinLose.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&curPage=%d&countEachPage=%d&startTime=%s&endTime=%s&sign=%s";
        
        // ��ѯ������Ϣ
        public static $URL_QUERY_ORDER_INFO = "/appaspx/QueryOrderInfo.aspx?gmAcc=%s&gmPwd=%s&orderId=%s&sign=%s";
        
        // �޸��������
        public static $URL_UPDATE_PLAYER_PWD = "/appaspx/UpdatePlayerPwd.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&oldPwd=%s&newPwd=%s&sign=%s";
        
        // API�µ�������ҵ���Ӯ�ܺ�
        public static $URL_QUERY_WIN_LOSE_SUM = "/appaspx/QueryWinLoseSum.aspx?gmAcc=%s&gmPwd=%s&startTime=%s&endTime=%s&sign=%s";
        
        // �����ز���
        public static $URL_PLAYER_OP = "/appaspx/PlayerOp.aspx?gmAcc=%s&gmPwd=%s&playerAcc=%s&op=%s&sign=%s";
    }
    
    class Tool
    {
        public static function md5($str)
        {
            $data = md5($str);
            $data = strtoupper($data);
            return $data;
        }
        
        public static function get($urlStr)
        {
            $fp = fopen($urlStr, 'r');
            $result = "";
            stream_get_meta_data($fp);
            while(!feof($fp))
            {
                $result .= fgets($fp, 1024);
            }
            return $result;
        }
        
        public static function genGuid() 
        {
            $charid = strtoupper(md5(uniqid(mt_rand(), true)));
            $hyphen = chr(45);// "-"
            $uuid = ""// "{"
            .substr($charid, 0, 8).$hyphen
            .substr($charid, 8, 4).$hyphen
            .substr($charid,12, 4).$hyphen
            .substr($charid,16, 4).$hyphen
            .substr($charid,20,12)
            ;// "}"
            
            $uuid = str_replace("-", "", $uuid);
            return $uuid;
        }
    }
?>