
POTI-board�p�e���v���[�g�u5u�v lot.180122
by sakots >> https://sakots.red/

���̃t�@�C���ꎮ��POTI-board v1.30 lot.050114�ȍ~�p�ɍ쐬���ꂽ�f�U�C���e���v���[�g�ł��B
�W����HTML5�ɑΉ��APaintBBSNEO��g�ݍ��܂��Ă��������܂����B�u�����[�v�Ɠǂ݂܂��B

���ǋL

PaintBBSNEO�̑g�ݍ��݂������Ă��������܂����Bfigune���񂠂肪�Ƃ��������܂��B
https://github.com/funige/neo/
NEO�̃o�[�W�����A�b�v�́A�ŐV�ł�.js�t�@�C����.css�t�@�C����
���ꂼ��PaingBBS.js��PaintBBS.css�ɖ��O��ς��ď㏑�����Ă��������B
NEO��p�ł��̂ŃA�v���b�g��jar�t�@�C���v��܂���B


���e�t�@�C������

template_ini.php  �e���v���[�g�ݒ�t�@�C��
5u_main.html      ���C�������X �e���v���[�g
5u_other.html     ���̑� �e���v���[�g
5u_paint.html     ���G���� �e���v���[�g
5u_catalog.html   �J�^���O �e���v���[�g
5u.css            �J�X�^�}�C�Y�p�X�^�C���V�[�g
5u_main.css       �e���v��
siihelp.php       ��p����HELP
palette.txt       ��p�p���b�g�f�[�^
PaingBBS.js       neo�{��
PaintBBS.css      neo�{��

���ݒ�

[ config.php ]

���G�����@�\���g�p����ꍇ�A�ݒ�� 2 �ɂ��ĉ������B
�@define(USE_PAINT, 2);

���p����A�v���b�g�͉���I��ł�NEO����ł��B
�@define(APPLET, 0);

����@�\�͎g���܂���B
�@define(USE_ANIME, 0);
�@define(DEF_ANIME, 0);

�R���e�B�j���[�͉摜����ł���悤�ł��B

[ picpost.php ]
NEO readme���
���M���ꂽ�摜��User-Agent�����ĕs���ȓ��e���ǂ����`�F�b�N���Ă���悤�ł��B
�A�v���ł�User-Agent���ȒP�ɋU���ł���̂ł����A���ߍ��݂�NEO�ł͋U���͓���̂ŁA
���̃`�F�b�N���O���K�v������܂��B
�Ƃ̂��ƂŁA

�@/*
�@if($h=='S'){
 �@   if(!strstr($u_agent,'Shi-Painter/')){
�@        unlink($full_imgfile);
�@        error("UA error�B�摜�͕ۑ�����܂���B");
�@        exit;
�@    }
�@    $ext = '.spch';
�@}else{
�@    if(!strstr($u_agent,'PaintBBS/')){
�@        unlink($full_imgfile);
�@        error("UA error�B�摜�͕ۑ�����܂���B");
�@        exit;
�@    }
�@    $ext = '.pch';
�@}
�@*/

�̕������R�����g�A�E�g���Ă��������B

���⑫

�Ǝ��^�O��Ή��A�����F�ς�����Ή��B
���[���A�h���X��URL���͗��͂��̂��������ʂȂ̂ŏ����܂����B

���ύX����

[2018/01/22]
�Egithub�Ɍ��J
�Etemplate_ini.php�̍œK��

���A�b�v�f�[�g�� template_ini.php �㏑��

[2018/01/16]
�E�O��URL����window.opener�Ōf���𑀍�ł���\������������C��

���A�b�v�f�[�g�� n5u_main.html template_ini.php �㏑��

[2018/01/13]
�EURL���͗�����
�E���X�t�H�[���\���̏ꍇ�ɏȗ����ꂽ���X���ǂ߂Ȃ��������C��

���A�b�v�f�[�g�� n5u_main.html n5u_other.html template_ini.php �㏑��

[2018/01/12]
�E���G�`����ʂ�UI���P
�ENEO��1.2.3�ɃA�b�v�f�[�g

���A�b�v�f�[�g�� n5u_paint.html n5u_main.css template_ini.php PaingBBS.js PaingBBS.css �㏑��

[2018/01/11]
�E�u���E�U��html�t�@�C�����L���b�V�������Ȃ��悤�ɂ���

���A�b�v�f�[�g�� n5u_main.html n5u_catalog.html template_ini.php �㏑��

[2018/01/10]
�EURL�ύX�A�܂��Ǘ��̂��₷���̊ϓ_����X�L���̃t�@�C������ύX

���A�b�v�f�[�g�͑S�ď㏑��

[2017/12/11]
�ENEO��1.2.0�ɍX�V
�E�f�t�H���g��CSS�X�V

���A�b�v�f�[�g�� 5u_paint.html 5u_main.css template_ini.php PaintBBS.css PaintBBS.js siihelp.php �㏑��

[2017/11/30]
�E�f�t�H���g��CSS�X�V
�E���̑��e���v���[�gCSS������������

���A�b�v�f�[�g��5u_main.css template_ini.php �㏑��

[2017/11/15]
�E�J�X�^�}�C�Y���₷���悤��CSS�𕪗�

���A�b�v�f�[�g��5u.css 5u_main.css template_ini.php �㏑��

[2017/11/04]
�E���J

[2017/11/05]
�E���X���ł��Ȃ��������P
�E�J�^���O���[�h����

���A�b�v�f�[�g�͑S�ď㏑��

[2017/11/05 2���]
�Esage�@�\�b�����
�E�J�^���O���[�h�f�t�H���g�l�ύX

���A�b�v�f�[�g�� 5u.css 5u_main.html 5u_catalog.html template_ini.php �㏑��

���Ō��

�D���ɉ������Ă����̂ŉ��ɐ����������܂��񂩂˂��B
